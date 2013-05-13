/** 
 * \file interfaceTexte.h
 * \brief Tous les affichages en mode texte seulement
 * Permet l'affichage du jeu en mode texte uniquement, les saisies se font au clavier.
 */

#ifndef INTERFACETEXT_H
#define	INTERFACETEXT_H

#include "plateau.h"
void interfaceTexte_afficherPlateau(const Plateau pPlateau);
void jeu_lancerModeTexte(Jeu pJeu, _Bool pGrillePredefinie);
#endif	/* INTERFACETEXT_H */

