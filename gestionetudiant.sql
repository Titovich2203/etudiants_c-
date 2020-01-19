-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le :  Dim 19 jan. 2020 à 22:35
-- Version du serveur :  10.4.8-MariaDB
-- Version de PHP :  7.3.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `gestionetudiant`
--

-- --------------------------------------------------------

--
-- Structure de la table `batiment`
--

CREATE TABLE `batiment` (
  `id` int(11) NOT NULL,
  `numBat` varchar(200) NOT NULL,
  `adresse` varchar(200) NOT NULL,
  `nom` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `batiment`
--

INSERT INTO `batiment` (`id`, `numBat`, `adresse`, `nom`) VALUES
(1, 'BAT0001', 'FASS', 'FASS_BAT'),
(2, 'BAT0002', 'MEDINA', 'MED_BAT');

-- --------------------------------------------------------

--
-- Structure de la table `boursier`
--

CREATE TABLE `boursier` (
  `id` int(11) NOT NULL,
  `idEtu` int(11) NOT NULL,
  `typeBourse` varchar(100) NOT NULL,
  `montant` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `boursier`
--

INSERT INTO `boursier` (`id`, `idEtu`, `typeBourse`, `montant`) VALUES
(1, 3, 'DEMI', 50000);

-- --------------------------------------------------------

--
-- Structure de la table `chambre`
--

CREATE TABLE `chambre` (
  `id` int(11) NOT NULL,
  `numCh` varchar(100) NOT NULL,
  `nbr` int(11) NOT NULL,
  `idBat` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `chambre`
--

INSERT INTO `chambre` (`id`, `numCh`, `nbr`, `idBat`) VALUES
(1, 'CH0001', 4, 1),
(2, 'CH0002', 5, 1),
(3, 'CH0001', 2, 2);

-- --------------------------------------------------------

--
-- Structure de la table `etudiant`
--

CREATE TABLE `etudiant` (
  `id` int(11) NOT NULL,
  `nom` varchar(200) NOT NULL,
  `prenom` varchar(200) NOT NULL,
  `isEtu` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `etudiant`
--

INSERT INTO `etudiant` (`id`, `nom`, `prenom`, `isEtu`) VALUES
(1, 'NOM1', 'PRENOM1', 1),
(2, 'NOM2', 'PRENOM2', 1),
(3, 'NOM3', 'PNOM3', 0),
(4, 'NOM4', 'PRENOM4', 0),
(5, 'NOM5', 'PRENOM5', 0),
(6, 'NOM6', 'PRENOM6', 0);

-- --------------------------------------------------------

--
-- Structure de la table `loger`
--

CREATE TABLE `loger` (
  `id` int(11) NOT NULL,
  `idEtudiant` int(11) NOT NULL,
  `idChambre` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `loger`
--

INSERT INTO `loger` (`id`, `idEtudiant`, `idChambre`) VALUES
(1, 4, 3),
(2, 5, 3),
(3, 6, 1);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `batiment`
--
ALTER TABLE `batiment`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `boursier`
--
ALTER TABLE `boursier`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idEtu` (`idEtu`);

--
-- Index pour la table `chambre`
--
ALTER TABLE `chambre`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idBat` (`idBat`);

--
-- Index pour la table `etudiant`
--
ALTER TABLE `etudiant`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `loger`
--
ALTER TABLE `loger`
  ADD PRIMARY KEY (`id`),
  ADD KEY `idEtutiant` (`idEtudiant`),
  ADD KEY `idChambre` (`idChambre`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `batiment`
--
ALTER TABLE `batiment`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `boursier`
--
ALTER TABLE `boursier`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT pour la table `chambre`
--
ALTER TABLE `chambre`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `etudiant`
--
ALTER TABLE `etudiant`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT pour la table `loger`
--
ALTER TABLE `loger`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `boursier`
--
ALTER TABLE `boursier`
  ADD CONSTRAINT `boursier_ibfk_1` FOREIGN KEY (`idEtu`) REFERENCES `etudiant` (`id`);

--
-- Contraintes pour la table `chambre`
--
ALTER TABLE `chambre`
  ADD CONSTRAINT `chambre_ibfk_1` FOREIGN KEY (`idBat`) REFERENCES `batiment` (`id`);

--
-- Contraintes pour la table `loger`
--
ALTER TABLE `loger`
  ADD CONSTRAINT `loger_ibfk_1` FOREIGN KEY (`idChambre`) REFERENCES `chambre` (`id`),
  ADD CONSTRAINT `loger_ibfk_2` FOREIGN KEY (`idEtudiant`) REFERENCES `etudiant` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
