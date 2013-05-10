/*!
 * \file main.c
 * \see Dictionnaire, Util, Plateau, Resolveur, Jeu, InterfaceNcurses, interfaceTexte
 * \mainpage Jeu de Boggle -- UE Projet
 * \author Antoine de Roquemaurel (G2.2)
 * \author Fabrice Valleix (G2.2)
 * \date 07/05/13 à 18:20:03
 * 
 * \section execution Éxecution du programme
 * Afin d'executer le programme, un fichier de test fonctionnel à été créer, celui-ci génère un executable
 * du nom de "./boggle", celui-ci est placé à la racine du projet.
 * 
 * Il doit être executé avec des arguments : 
 * \li \code ./boggle --solveur \endcode Lance un solveur, c'est-à-dire la version 1, 
 * \li \code ./boggle --text \endcode Lance le jeu en mode text, soit la version 2 
 * \li \code ./boggle --ncurses \endcode Lance le jeu avec le mode ncurses, la version 3
 * 
 * \section version1 Version 1 : Le résolveur
 *  Afin d'appeller la version 1 de l'application, l'executable doit être appellé 
 * à l'aide de l'argument \-\-solveur
 * 
 * Dans cette version, une grille carrée de la taille demandée par l'utilisateur est génére, en tenant compte de la 
 * fréquence des lettres dans la langue Française.
 * Une fois la grille générée, la position d'une case est demandée à l'utilisateur, l'utilisateur
 * entre donc les deux coordonnées, et tous les mots commençant par cette case seront affichés à l'écran.
 * 
 * Attention, les coordonnées de la grille commences à zéro.
 * 
 * \section version2 Version 2 : Le mode texte 
 * Afin d'appeller la version 2, l'executable doit être appellé à l'aide de l'argument \-\-text
 * 
 * Cette version fait appel à la version 1, en effet, au lancement de l'application, il est de nouveau demandé
 * la taille de la grille, ensuite l'intégralité de la grille générer est résolue.
 * Une fois cette étape franchie, l'utilisateur à 3 minutes pour entrer le plus de mots possibles, l'application lui 
 * signalant si le mot est accepté ou non, une fois ce temps impartis, la solution est affichée, puis le nombre de points 
 * obtenu par le joueur.
 * 
 * \section version3 Version 3 : L'interface Ncurses
 * Afin d'appeller la version 3, l'executable doit être appellé à l'aide de l'argument \-\-ncurses
 * 
 * Cette version suit le même principe que la version précédente, à la différence près qu'elle utilise la bibliothèque Ncurses.
 * Ainsi, la saisie des mots se fait dorénavant avec les touches fléchées du clavier, et espace pour ajouter une lettre au mot.
 * Pour proposer le mot surligné, la touche entrée doit être appuyée. 
 * Il est également possible de demander le nombre de mots commençant par la case séléctionnée à l'aide de la touche h.
 *
 * Une fois les 3 minutes écoulées, les mots proposés par l'utilisateur et le nombre de points obtenus sont affichés, 
 * il est proposé à l'utilisateur d'afficher la solution complète.
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>

#include "dictionnaire.h"
#include "util.h"
#include "plateau.h"
#include "resolveur.h"
#include "jeu.h"
#include "interfaceNcurses.h"
#include "interfaceTexte.h"

/** \enum TypeJeu Enumeration contenant le type de Jeu possible*/
typedef enum {TEXTE, SOLVEUR, NCURSES}TypeJeu;

/**
 * Affiche une erreur de paramètres.
 * @param pNomExe Le nom de l'executable
 * @return Code de retour du programme
 */
int mauvaisParametre(char* pNomExe) {
    printf("Usage %s --text|--solveur|--ncurses [--grilleFixe]\n", pNomExe);
    fprintf(stderr, "Mauvais paramètres\n");
    return 1;
}

/**
 * Lance le jeu de Boggle en fonction des paramètres
 * @param argc Nombre de paramètres
 * @param argv Tableau de paramètres
 * @return Le code de retour du programme.
 */
int main(int argc, char** argv) {
    Couple taille;
    TypeJeu typeJeu;
    _Bool grillePredefinie;
    
    char buff1[256];
    taille.x = taille.y = 0;
    
    if(argc > 3) {
        return mauvaisParametre(argv[0]);
    }
    
    grillePredefinie = (util_cherchePremiereOccurenceDansTableau(argv, argc, "--grilleFixe") != -1);
    if(util_cherchePremiereOccurenceDansTableau(argv, argc, "--text") != -1) {
        typeJeu = TEXTE;
    } else if(util_cherchePremiereOccurenceDansTableau(argv, argc, "--solveur") != -1) {
        typeJeu = SOLVEUR;
    } else if(util_cherchePremiereOccurenceDansTableau(argv, argc, "--ncurses") != -1) {
        typeJeu = NCURSES;
    } else {
        return mauvaisParametre(argv[0]);
    }
   
    if(!grillePredefinie) {
        
        do {
            printf("Veuillez entre la taille de la grille de boggle. "
                    "Les valeurs doivent être comprise entre 3 et 15");
            printf("\nTaille de la grille: ");
            util_lireChaine(buff1, 3);

            taille.x =  taille.y = atoi( buff1);
        } while(taille.x < 3 || taille.x > 15 || taille.y < 3 || taille.y > 15);
    } else {
        taille.x = taille.y = 4;
    }
    Jeu jeu = jeu_nouveau("Complet.txt", taille, 50);
    switch(typeJeu) {
        case TEXTE:
            jeu_lancerModeTexte(jeu, grillePredefinie);
            break;
        case SOLVEUR:
            jeu_lancerModeSolveur(jeu, grillePredefinie);
            break;
        case NCURSES:
            jeu_lancerModeNcurses(jeu, grillePredefinie);
            break;
    }

    return (EXIT_SUCCESS);
}

