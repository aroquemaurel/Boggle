/* 
 * File:   solution.h
 * Author: aroquemaurel
 *
 * Created on 14 avril 2013, 20:47
 */

#ifndef SOLUTION_H
#define	SOLUTION_H

typedef struct {
    char** mots;
    unsigned int nbMots;
    unsigned int nbPointsTotal;
} Solution;

Solution solution_creer(void);
void solution_ajouterMot(Solution* pSolution, const char* mot);
void solution_afficher(const Solution pSolution);
void solution_detruire(Solution* pSolution);
_Bool solution_motEstPresent(const Solution pSolution, const char* pMot);
int solution_nbPoints(Solution pSolution);
#endif	/* SOLUTION_H */

