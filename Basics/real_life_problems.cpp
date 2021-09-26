1::
SELECT id, COUNT(id), SUM(id) AS sum_of_id, AVG(id) AS avg_of_id FROM block_request where id >300;

+-----+-----------+-----------+-----------+
| id  | COUNT(id) | sum_of_id | avg_of_id |
+-----+-----------+-----------+-----------+
| 301 |        45 |     14535 |  323.0000 |
+-----+-----------+-----------+-----------+
1 row in set (0.03 sec)



2::
Finding the duplicate id in use:
SELECT id, block_type FROM block_request GROUP BY id HAVING COUNT(id) > 1;

>> Empty Set

3::
Union with ORDER BY
CORRECT ->
SELECT id, block_type FROM block_request WHERE id BETWEEN 200 and 210
UNION
SELECT id, block_type FROM block_request WHERE id BETWEEN 190 and 200 ORDER BY id;

INCORRECT ->
SELECT id, block_type FROM block_request WHERE id BETWEEN 200 and 210 ORDER BY id DESC 
UNION
SELECT id, block_type FROM block_request WHERE id BETWEEN 190 and 200 ORDER BY id;

we can't have ORDER by in both the terms and also there are many constartint that quey has while working with UNION






