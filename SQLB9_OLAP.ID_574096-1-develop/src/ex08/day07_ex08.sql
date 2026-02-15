SELECT 
    p.address,
    pz.name,
    COUNT(po.id) AS count_of_orders
FROM person p
JOIN person_visits pv ON p.id = pv.person_id
JOIN pizzeria pz ON pv.pizzeria_id = pz.id
JOIN menu m ON pz.id = m.pizzeria_id
JOIN person_order po ON p.id = po.person_id AND m.id = po.menu_id
GROUP BY p.address, pz.name
ORDER BY p.address, pz.name;