WITH RECURSIVE seq AS (
    SELECT 1 AS n
    UNION ALL 
    SELECT n+1
    FROM seq 
    WHERE n < 1000
),
chars AS (
    SELECT 
        u.content_id,
        u.content_text,
        seq.n,
        SUBSTRING(LOWER(u.content_text),seq.n,1) AS ch,
        SUBSTRING(LOWER(u.content_text),seq.n-1,1) AS prev_ch
    FROM user_content u
    JOIN seq 
       ON seq.n <= CHAR_LENGTH(u.content_text)
)
SELECT 
 content_id, content_text AS original_text,
 GROUP_CONCAT(
    CASE 
        WHEN n=1 THEN UPPER(ch)
        WHEN prev_ch IN (' ','-') THEN UPPER(ch)
        ELSE ch
    END
    ORDER BY n
    SEPARATOR ''
   ) AS converted_text
FROM chars
GROUP BY content_id, content_text;