WITH age_stats AS (
    SELECT 
        address,
        MAX(age) AS max_age,
        MIN(age) AS min_age,
        ROUND(AVG(age), 2) AS average_age
    FROM person
    GROUP BY address
)
SELECT 
    address,
    ROUND((max_age - (min_age::numeric / max_age::numeric)), 2) AS formula,
    average_age AS average,
    (max_age - (min_age::numeric / max_age::numeric)) > average_age AS comparison
FROM age_stats
ORDER BY address;