#include <unistd.h>
#include "define.h" 

/*!
 * \brief Ecrit dans le fichier data.txt les temperatures interieure et exterieur
 *
 * Cette fonction ecrit dans le fichier data.txt les valeurs de temperatures.
 * Elle efface le fichier puis ecrit la valeur exterieure puis interieure sur les lignes 1 et 2
 * Ensuite elle ecrit true pour la valeur du chauffage. Ceci est la valeur par default et doit 
 * etre immediatement remplacer par un appel a visualisationC
 *
 * \param[in] myTemp une structure temp_t contenant les valeurs de temperatures
 *
 * \author FEBVRE Alexandre
 */
void visualisationT(temp_t myTemp);
