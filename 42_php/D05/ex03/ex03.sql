INSERT INTO ft_table
    (login, group_db, creation_date)
SELECT nom, 'other', date_naissance
FROM fiche_personne
WHERE LENGTH(nom) < 9 AND nom LIKE '%a%'
ORDER BY nom ASC
LIMIT 10;

-- CREATE TABLE tmp SELECT prenom, date_naissance FROM fiche_personne WHERE CHAR_LENGTH(prenom) < 9 AND LOCATE('a', prenom) ORDER BY prenom ASC;
-- INSERT INTO ft_table(login, group_db, creation_date)VALUES(SELECT prenom FROM tmp, 'other', SELECT date_naissance FROM tmp);
-- SELECT * from ft_table LIMIT 10;



-- CREATE TABLE tmp SELECT prenom, date_naissance FROM fiche_personne WHERE CHAR_LENGTH(prenom) < 9 AND LOCATE('a', prenom) ORDER BY prenom ASC;

-- SELECT login, group_db, creation_date from ft_table UNION SELECT prenom, "other", date_naissance FROM tmp;

-- DROP TABLE tmp;

-- SELECT * FROM ft_table ORDER BY login ASC;