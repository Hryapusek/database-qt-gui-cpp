/* This file was generated by ODB, object-relational mapping (ORM)
 * compiler for C++.
 */

DROP TABLE IF EXISTS "AUTO_PERSONNEL" CASCADE;

CREATE TABLE "AUTO_PERSONNEL" (
  "ID" BIGSERIAL NOT NULL PRIMARY KEY,
  "FIRST_NAME" VARCHAR(20) NULL,
  "LAST_NAME" VARCHAR(20) NULL,
  "PATHER_NAME" VARCHAR(20) NULL);

