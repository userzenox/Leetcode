SELECT today.id
FROM Weather today
JOIN Weather yesterday
  ON DATEDIFF(today.recordDate, yesterday.recordDate) = 1
  AND today.temperature > yesterday.temperature;
