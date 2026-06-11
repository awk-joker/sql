SELECT 
    SUM(price) AS total_products_value,
    AVG(quantity) AS average_stock_quantity,
    COUNT(*) AS total_products_count,
    MIN(price) AS min_product_price,
    MAX(price) AS max_product_price,
    SUM(price * quantity) AS total_inventory_value
FROM products 
WHERE 
    category = 'electronics'
    AND price > 0
GROUP BY 
    category
HAVING 
    SUM(price) > 10000
ORDER BY 
    total_inventory_value DESC
LIMIT 10;

SELECT 
    s.name AS student_name,
    TIMESTAMPDIFF(YEAR, s.birth, CURDATE()) AS age,
    z.name AS department
FROM student s
JOIN specialty z ON s.dept_id = z.id
WHERE z.name <> 'Computer Science';
