ALTER TABLE fiche_personne CHANGE date_naissance birthdate datetime;
SELECT nom, prenom ,birthdate FROM fiche_personne WHERE YEAR(birthdate)='1932' ORDER BY nom ASC;