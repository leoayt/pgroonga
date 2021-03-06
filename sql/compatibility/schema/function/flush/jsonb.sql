CREATE TABLE logs (
  id int,
  record jsonb
);

INSERT INTO logs VALUES (1, '{"message": "Hello World"}');
INSERT INTO logs VALUES (2, '{"message": "This is a pen"}');
INSERT INTO logs VALUES (3, '{"message": "Good-by World"}');

CREATE INDEX pgroonga_index ON logs
  USING pgroonga (record pgroonga.jsonb_ops);

SELECT pgroonga.flush('pgroonga_index');

DROP TABLE logs;
