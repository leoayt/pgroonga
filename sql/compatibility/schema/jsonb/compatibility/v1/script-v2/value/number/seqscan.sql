CREATE TABLE fruits (
  id int,
  items jsonb
);

INSERT INTO fruits VALUES (1, '{"apple":  100}');
INSERT INTO fruits VALUES (2, '{"banana":  30}');
INSERT INTO fruits VALUES (3, '{"peach":  150}');

SET enable_seqscan = on;
SET enable_indexscan = off;
SET enable_bitmapscan = off;

SELECT id, items
  FROM fruits
 WHERE items &` 'type == "number" && number <= 100'
 ORDER BY id;

DROP TABLE fruits;
