SELECT gs.missing_date
FROM generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day'::interval) AS gs(missing_date)
LEFT JOIN person_visits pv ON gs.missing_date = pv.visit_date 
    AND pv.person_id IN (1, 2)
WHERE pv.visit_date IS NULL
ORDER BY gs.missing_date;