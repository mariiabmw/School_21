SELECT 
    p.id,
    p.name,
    p.age,
    p.gender,
    p.address,
    pz.id,
    pz.name,
    pz.rating
FROM person p
CROSS JOIN pizzeria pz
ORDER BY p.id, pz.id;