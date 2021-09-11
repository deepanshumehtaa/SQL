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
   id       INT PRIMARY KEY,
   roll_no  INT NOT NULL,
   class    INT NOT NULL,
   name     VARCHAR(10),
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

2. Dropping INDEX:>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

DROP INDEX index_name ON table_name
[algorithm_option | lock_option];






