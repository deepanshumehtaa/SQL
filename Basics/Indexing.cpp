MySql Gives Plenty of options to implement Indexing and also other options to manage it:

1. Creating indexes:
2. Invisible indexes – covers the index visibility and shows you how to make an index visible or invisible.
3. Unique indexes – uses the unique indexes to ensure distinct values stored in a column. 
4. Descending indexes –  shows you how to use descending indexes to increase query performance.
5. Composite indexes – illustrates the application of composite indexes and shows you when to use them to speed up your queries.
6. Clustered indexes – explains the clustered indexes in InnoDB tables.


7. Listing table indexes – provides you with a statement to list all indexes of a table.
8. Removing indexes – shows you how to remove an existing index of a table.

Advanced:
USE INDEX hint –  shows you how to use the USE INDEX hint to instruct the query optimizer to use the only list of specified indexes to find rows in a table.
FORCE INDEX hint – shows you how to use the FORCE INDEX hint to force the query optimizer to use specified indexes to select data from a table.

  
1. CREATING INDEX:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>
By Default, MySql creates a BTree index
other indexes are:
B+ Trees
Hash Indexes

# 1
CREATE TABLE class_table(
   # Feilds
   stud_id  INT AUTO_INCREMENT,
   roll_no  INT NOT NULL,
   class    INT NOT NULL,
   name     VARCHAR(10),
   
   # Constraints
   PRIMARY KEY(stud_id),
   UNIQUE KEY unique_roll_no(roll_no),                  # unique_roll_no is the name of Uniuque Constraint
   CONSTRAINT UC_roll_no_class UNIQUE (Class, roll_no)
   
   # Creating Indexing
   INDEX (roll_no, class) 
);


# 2
CREATE INDEX <index_name> ON <table_name> (column_list)
eg:
  # Index on class column
  CREATE INDEX idx_class ON class_table(Class);
  
# 3
To see the Created Index on class_table
SHOW INDEXES FROM employees;

Ref:  https://medium.com/@mena.meseha/what-is-the-difference-between-mysql-innodb-b-tree-index-and-hash-index-ed8f2ce66d69
      https://www.mysqltutorial.org/mysql-index/mysql-drop-index/

2. Invisible INDEX:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

See the Hidden Indexes on Tables::

SHOW INDEXES FROM <table_name> 
IN <db_name>;

--OR--
  
SHOW INDEXES FROM <db_name>.<table_name>;

+++point synonyms

=>
INDEX <---> KEYS
FROM <---> IN

Eg:

SHOW INDEX IN table_name 
FROM database_name;

===
  
SHOW KEYS FROM tablename
IN databasename;

=>
The primary key index always has the name of "PRIMARY"  

SHOW INDEX GIVES THE INFO like:

1. collation :: tells how the index is stored
      A --> Ascending order
      B --> Descending order
      NULL  Not Sorted

2. null
      return YES if NULL or Blank values are there 

3. index_type:
      index method used such as:: BTREE, HASH, RTREE, or FULLTEXT.

4. cardinality ::
      Unique Values in the Index
      

# SHOW THE INVISIBLE INDEX
SHOW INDEXES FROM contacts
WHERE visible = 'NO';



3. Unique indexes:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

CREATE UNIQUE INDEX <index_name>
ON table_name(index_column_1,index_column_2,...);

But SQL creates the Uniue index for Unique Constarint so, no need of Run above  query



4. Descending indexes:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
By default the

# Eg 1
CREATE TABLE t(
    a INT NOT NULL,
    b INT NOT NULL,
    INDEX a_asc_b_desc(a ASC, b DESC)
);

# Eg 2
CREATE TABLE class_table(
   # Feilds
   stud_id  INT AUTO_INCREMENT,
   roll_no  INT NOT NULL,
   class    INT NOT NULL,
   name     VARCHAR(10),
   
   # Constraints
   PRIMARY KEY(stud_id),
   UNIQUE KEY unique_roll_no(roll_no),                  # unique_roll_no is the name of Uniuque Constraint
   CONSTRAINT UC_roll_no_class UNIQUE (Class, roll_no),
   
   # Creating Indexing
   INDEX new_idx(roll_no ASC, class DESC) 
);

5. Composite indexes:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
A composite index -OR- Multiple-Column Index is an index on multiple columns (up to 16 columns).


  
+++ If you specify the columns in the right order in the index definition, a single composite index can speed up these kinds of queries on the same table.
  
  
  
