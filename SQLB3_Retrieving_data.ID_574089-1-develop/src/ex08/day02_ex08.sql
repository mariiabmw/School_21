SELECT DISTINCT p.name
FROM person_order po
JOIN menu m ON po.menu_id = m.id
JOIN person p ON po.person_id = p.id
WHERE p.gender = 'male'
  AND p.address IN ('Moscow', 'Samara')
  AND (m.pizza_name LIKE '%pepperoni%' OR m.pizza_name LIKE '%mushroom%')
ORDER BY p.name DESC;