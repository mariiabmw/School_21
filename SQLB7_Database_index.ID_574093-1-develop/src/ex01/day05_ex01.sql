SET enable_seqscan = off;
EXPLAIN ANALYZE
SELECT m.pizza_name, pz.name as pizzeria_name
FROM menu m
JOIN pizzeria pz
    ON m.pizzeria_id = pz.id;