WITH visits AS (
    SELECT 
        pz.id,
        pz.name,
        COUNT(pv.id) AS count
    FROM pizzeria pz
    LEFT JOIN person_visits pv ON pz.id = pv.pizzeria_id
    GROUP BY pz.id, pz.name
),
orders AS (
    SELECT 
        pz.id,
        pz.name,
        COUNT(po.id) AS count
    FROM pizzeria pz
    LEFT JOIN menu m ON pz.id = m.pizzeria_id
    LEFT JOIN person_order po ON m.id = po.menu_id
    GROUP BY pz.id, pz.name
)
SELECT 
    COALESCE(v.name, o.name) AS name,
    COALESCE(v.count, 0) + COALESCE(o.count, 0) AS total_count
FROM visits v
FULL OUTER JOIN orders o ON v.id = o.id
ORDER BY total_count DESC, name ASC;