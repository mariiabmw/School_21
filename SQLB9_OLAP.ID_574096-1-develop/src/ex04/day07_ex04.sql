SELECT 
    p.name,
    COUNT(pv.id) AS count_of_visits
FROM person p
JOIN person_visits pv ON p.id = pv.person_id
GROUP BY p.id, p.name
HAVING COUNT(pv.id) > 3
ORDER BY count_of_visits DESC, p.name ASC;