WITH order_counts AS (
    SELECT 
        pz.name,
        COUNT(po.id) AS count,
        'order' AS action_type
    FROM person_order po
    JOIN menu m ON po.menu_id = m.id
    JOIN pizzeria pz ON m.pizzeria_id = pz.id
    GROUP BY pz.id, pz.name
    ORDER BY count DESC
    LIMIT 3
),
visit_counts AS (
    SELECT 
        pz.name,
        COUNT(pv.id) AS count,
        'visit' AS action_type
    FROM person_visits pv
    JOIN pizzeria pz ON pv.pizzeria_id = pz.id
    GROUP BY pz.id, pz.name
    ORDER BY count DESC
    LIMIT 3
)
SELECT * FROM order_counts
UNION ALL
SELECT * FROM visit_counts
ORDER BY action_type ASC, count DESC;