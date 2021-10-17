Amazon::

Q.
Given a shoping data, find the % spend of each order of customer
(ie. if he has 3 orders, then their %s are like 55, 33, 11 sum to 100), 
rounded the each percentage to nearest whole num.
Show it like: name, detail and percentage
we have two tables
1. orders
	id
	cust_id
	cost
	quantity
	detail

2. customers
	id
	name
	address


Ans:
	Approach:
	
	1. Hence we need combined data so, JOIN it inner to eleminate the Null Values
	2. use aggregate Function SUM (Trick: Try to use SUM as windows Function)
	3. then finc the percentage
	4. apply round() on percentage value
	
	Query:
	
	Step 1,2:

	SELECT name, detail, SUM(quantity) OVER (PARTITION BY name)
	FROM orders
	INNER JOIN customers;
	# the partion by name is ~equilent~ to GROUP BY name
	
	Step 3:
	SELECT name, detail, cost/SUM(quantity) OVER (PARTITION BY name)::FLOAT *100
	FROM orders
	INNER JOIN customers;

	Step 4:
	SELECT name, detail, round( cost / SUM(quantity) OVER (PARTITION BY name)::FLOAT *100, 0) as percentage_cost
	FROM orders o
	INNER JOIN customers c;
// Learning::
1. 	when we are using GROUP BY, the windows agrregate function behave like Grouping Function
	like AVG, COUNT, SUM, COUNT, etc.

2.	For Inner Join it is alwasys best practice to use table alias like:
	like:
		select id, COUNT(id) FROM gate_pass INNER JOIN gate_pass_details;
		
		-- The above error throws the error "Ambiguous type", as id is present in both the tables
		
		>>
		The Correct Way:
		select GP.id, COUNT(GP.id)
		FROM gate_pass as GP
		INNER JOIN gate_pass_details as GPD
		LIMIT 10, 20;
		// Feature about the above Query:
		1.  query brings 20 rows start from 11 to 20, the offset means only 20.
		2.  Both the tables in above query is interchangeable
		3.  The Query is really Expensive that we havent passed the Join Parameter ie. ON, so
			if table1 have 50 rows and table2 have 200 rows and they linked with an FK, then final inner join
			has 50*200 rows.
			
		So, More Correct way:
		>>
		select GP.id, return_number, force_closed_by, GPD.id 
		FROM gate_pass_details as GPD 
		INNER JOIN gate_pass as GP 
		ON GPD.gate_pass_id=GP.id
		
		# The inner join is the default Join used when you don’t specify the type of Join in MySql.
		# it only return the met conditional rows and not the null values.
		
3. GROUP BY on Multiple Columns:

>>
SELECT GP.id, return_number, force_closed_by, GPD.id 
FROM gate_pass_details as GPD 
GROUP BY created_by, updated_by

first we group our table by unique values of "created_by", then check what are the unique values in "updated_by" in created at
mix all the result then show it:
ref: https://stackoverflow.com/questions/2421388/using-group-by-on-multiple-columns

Remember you can join as well as GROUP BY in same query.


4. DISTINCT always written with Select like

SELECT DISTINCT id
FROM ......
...;

Remember DISTINCT works on entire row ie.

stud_name 	from	class
Deepu		FGC		10
Deepu		FGC		11

+ they are DISTINCT

5. round() in SQL works similar to the python
	just give round(value, digits after decimal)














