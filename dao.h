#ifndef DAO_H_INCLUDED
#define DAO_H_INCLUDED

namespace dao
{
    MysqlDB *db = new MysqlDB();
    MYSQL_RES* getAllBatiments()
    {
        string sql = "SELECT *,(SELECT count(*) FROM chambre C WHERE idBat = B.id) FROM batiment B";
        //MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    MYSQL_RES* getBatimentById(int id)
    {
        //MysqlDB *db = new MysqlDB();
        ostringstream concat;
        concat<<"SELECT * FROM batiment WHERE id = '"<<id<<"' ";
        return db->executeSelect(concat.str());
    }
    MYSQL_RES* getBatimentByNum(string num)
    {
        //MysqlDB *db = new MysqlDB();
        ostringstream concat;
        concat<<"SELECT *,(SELECT count(*) FROM chambre C WHERE idBat = B.id) FROM batiment B WHERE numBat = '"<<num<<"' ";
        return db->executeSelect(concat.str());
    }
    MYSQL_RES* getAllChambres()
    {
        string sql = "SELECT *, (SELECT count(*) FROM loger WHERE idChambre = C.id) FROM chambre C";
        //MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    MYSQL_RES* getChambresByIdBat(unsigned int id)
    {
        stringstream concat;
        //MysqlDB *db = new MysqlDB();
        concat << "SELECT *, (SELECT count(*) FROM loger WHERE idChambre = C.id) FROM chambre C WHERE idBat = "<<id;
        return db->executeSelect(concat.str());
    }
    MYSQL_RES* getChambresByIdAndNum(string num, unsigned int id)
    {
        stringstream concat;
        //MysqlDB *db = new MysqlDB();
        //cout << num << " " << id << endl;
        //system("pause");
        concat << "SELECT *, (SELECT count(*) FROM loger WHERE idChambre = C.id) FROM chambre C WHERE numCh = '"<<num<<"' AND idBat = "<<id;
        //cout << concat.str() << endl;
        //system("pause");
        return db->executeSelect(concat.str());
    }
    MYSQL_RES* getAllEtudiants()
    {
        string sql = "SELECT * FROM etudiant E WHERE isEtu = 1";
        //MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    MYSQL_RES* getAllBoursier()
    {
        string sql = "SELECT E.id, E.nom, E.prenom,B.typeBourse,B.montant FROM boursier B, etudiant E WHERE idEtu = E.id";
        //MysqlDB *db = new MysqlDB();
        return db->executeSelect(sql);
    }
    MYSQL_RES* getAllLoger()
    {
        string sql = "SELECT E.id, E.nom, E.prenom ,C.numCh, B.numBat FROM loger L, etudiant E, chambre C, batiment B WHERE L.idEtudiant = E.id AND L.idChambre = C.id AND C.idBat = B.id";

        return db->executeSelect(sql);
    }
};

#endif // DAO_H_INCLUDED
