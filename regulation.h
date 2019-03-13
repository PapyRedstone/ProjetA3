#include "define.h"

/*!
 * \struct PID_param
 *
 * \brief definit les parametres d'utilisation de la regulation PID
 * \author FEBVRE Alexandre
 */
typedef struct{
  float Kp,Kd,Ki;  /*!< Les parametres du PID*/
  float dt;        /*!< La duree d'un intervalle*/
  float t;         /*!< Le temps totale qui c'est ecoule*/
  float lastTint;  /*!< La derniere temperature interieure*/
  float lasterror; /*!< La derniere erreur*/
}PID_param;

/*!
 * \brief Cette fonction est un fonction de test
 *
 * Cette fonction teste la regulation de la temperature
 *
 * \param[in] regul choix de la regulation (1: Tout ou Rien, 2 : PID)
 * \param[in] csgn la consigne (la temperature a obtenir)
 * \param[in] tabT un tableau des temperatures interieure sucessif
 * \param[in] nT le nombre de temperature dans le tableau tabT
 *
 * \return la commande de la deniere iteration de la regulation
 *
 * \author FEBVRE Alexandre
 */
float regulationTest(int regul,float csgn,float* tabT, int nT);

/*!
 * \brief Fonction de regulation de la temperature en tout ou rien
 *
 * Retourne la puissance du chauffage. Si la temperature est superieure a la consigne, 
 * on retourne 0, si la temperature est inferieure a la consigne on retourne 40
 *
 * \param[in] csgn la consigne
 * \parma[in] Tint
 *
 * \return la commande du chauffage
 *
 * \author FEBVRE Alexandre
 */
float ToR(float csgn, float Tint);

/*!
 * \brief Fonction de regulation de la temperaute en PID
 *
 * Cette fonction calcule la commande de temperature en utilisant la methode PID (proportionnel, Integral, derive)
 *
 * \param[in] csgn la consigne de temperature
 * \param[in] Tint la temperature actuelle
 * \param[in] param les parametres du PID
 * \param[out] param les dernieres valeurs de temperature et d'erreur sont mises a jour
 *
 * \return la commande du chauffage
 *
 * \author FEBVRE Alexandre
 */
float PID(float csgn, float Tint, PID_param *param);
