/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "AUTO_PERSONNEL" CASCADE;

CREATE TABLE "AUTO_PERSONNEL" (
  "ID" BIGSERIAL NOT NULL PRIMARY KEY,
  "FIRST_NAME" VARCHAR(20) NULL,
  "SECOND_NAME" VARCHAR(20) NULL,
  "FATHER_NAME" VARCHAR(20) NULL);

