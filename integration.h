#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "define.h"
#include "simulateur.h"

/*!
 * \brief fonction de test genrale
 *
 * Cette fonction sert a les test d'integration du projet.
 * Cette fonction execute nbIterations de la simulation de temperature
 * avec le choix de la fonction de chauffage,
 *
 * \param[in] regul choix du calcul de la regulation (Tout ou Rien ou PID)
 * \param[in] tInit la temperature interieure et exterieure initial
 * \param[in] nIterations le nombre de simulations a effectuer
 *
 * \author FEBVRE Alexandre
 */
void integrationTest(int regul,temp_t tInit,int nIterations);
