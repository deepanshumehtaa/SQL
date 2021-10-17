# Window functions  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

from django.db.models.expressions import Window
from django.db.models.functions import RowNumber
from django.db.models import F


Aggregate Func: 	AVG, MIN, MAX, COUNT, COUNT_BIG, CHECKSUM_AGG, STDEV, STDEVP, VAR, VARP
Ranking :			RANK, DENSE_RANK, ROW_NUMBER
Analytic:			LAG, LEAD, FIRST_VALUE, LAST_VALUE, PERCENT_RANK, PERCENTILE_CONT, PERCENTILE_DISC, CUME_DIST

## Ranking .....................................................................

Q. Show me highest salries in each department? (all the data is in single table)
   columns are: name, salary and department
A. 
>> 	SELECT department, salary, rank
	RANK() OVER (PARTATION BY department order by salary) as rank
	FROM salary;


## RowNumber: https://docs.djangoproject.com/en/3.2/ref/models/database-functions/#rownumber
Computes the row number according to the ordering of either the frame clause or the ordering of the whole query if there is no partitioning of the window frame.


results = Entry.objects.annotate(row_number=Window(expression=RowNumber(),
							     partition_by=[F('client')],
    							 order_by=F('created').desc()))
    				   .order_by('row_number', 'client')


