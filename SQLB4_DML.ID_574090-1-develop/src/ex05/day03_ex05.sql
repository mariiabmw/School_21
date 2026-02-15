SELECT DISTINCT pz.name AS pizzeria_name
FROM person_visits pv
JOIN person p ON pv.person_id = p.id
JOIN pizzeria pz ON pv.pizzeria_id = pz.id
WHERE p.name = 'Andrey'
  AND pz.id NOT IN (
    SELECT DISTINCT m.pizzeria_id
    FROM person_order po
    JOIN menu m ON po.menu_id = m.id
    WHERE po.person_id = (SELECT id FROM person WHERE name = 'Andrey')
  )
ORDER BY pz.name;