#include <unistd.h>
#include "define.h"

/*!
 * \brief Ecrit dans le fichier data.txt le status du chauffage
 *
 * Cette fonction ecrit dans le fichier data.txt l'etat du chauffage.
 * Elle l'ecrit apres les temperatures, sur la troisieme ligne.
 * Ecrit true si la puissance est differente de 0, false si elle vaut 0.
 *
 * \param[in] puissance_f la puissance du chauffage
 *
 * \author FEBVRE Alexandre
 */
void visualisationC(float puissance_f);
