
/*
Leetcode 595. Big Countries

Test Case:
{"headers": {"World": ["name", "continent",	"area",	"population", "gdp"]}, "rows": {"World": [["Afghanistan", "Asia", 652230, 25500100, 20343000000], ["Albania", "Europe", 28748, 2831741, 12960000000], ["Algeria", "Africa", 2381741, 37100000, 188681000000], ["Andorra", "Europe", 468, 78115,	3712000000], ["Angola", "Africa", 1246700, 20609294, 100990000000]]}}

Next challenges: Delete Duplicate Emails, Classes More Than 5 Students, Shortest Distance in a Line

Runtime: 2915 ms
Your runtime beats 13.60 % of mysql submissions.

*/

# Write your MySQL query statement below
select name, population, area from World where area>3000000 or population>25000000 
