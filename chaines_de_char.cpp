#include <iostream>

int i;
// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);
size_t LongueurChaine(const char* chaine){
    // Sauvegarde du pointeur initial vers le début de la chaîne
    // On stocke cette adresse pour pouvoir calculer la différence plus tard
    const char* debut = chaine;
    
    // Boucle qui parcourt la chaîne caractère par caractère
    // *chaine déréférence le pointeur pour obtenir le caractère pointé
    // La condition s'arrête quand on rencontre le caractère nul '\0' (fin de chaîne)
    while (*chaine != '\0') {
        // Incrémentation du pointeur : on le fait avancer d'une position en mémoire
        // chaine++ fait passer au caractère suivant dans la chaîne
        // En C++, l'arithmétique des pointeurs tient compte de la taille du type
        // donc chaine++ avance exactement de sizeof(char) = 1 octet
        chaine++;
    }
    
    // Calcul de la longueur par différence d'adresses mémoire
    // chaine pointe maintenant sur le '\0' à la fin de la chaîne
    // debut pointe toujours sur le premier caractère
    // La soustraction donne le nombre d'éléments (char) entre les deux adresses
    // C'est exactement la longueur de la chaîne sans compter le '\0'

    // Exemple concret avec la chaîne "Hello" :
    // Mémoire : [H][e][l][l][o][\0]
    //            ↑           ↑
    //          debut       chaine (après boucle)
          
    // Distance : chaine - debut = 5 (longueur de "Hello")
    return chaine - debut;
}
void CopierChaine(char* destination, const char* source) {
    // À implémenter :
    // 1. Tant que le caractère source n'est pas '\0'
    while(*source != '\0'){
    // 2. Copier le caractère source vers destination
        *destination = *source;
    // 3. Avancer les deux pointeurs
        destination++;
        source++; 
    }
    // 4. Ajouter '\0' à la fin de destination
        *destination = '\0';
}
void ConcatenerChaines(char* destination, const char* source) {
    // À implémenter :
    // 1. Trouver la position du '\0' dans destination
    while(*destination != '\0'){
        destination = destination++;
    }
    // 2. À partir de cette position, copier source
    while(*source != '\0'){
        *destination = *source;
        source++;
        destination++;
    }
     // 3. S'arrêter au '\0' de source et l'ajouter
        *destination = '\0';

}
char* TrouverCaractere(const char* chaine, char caractere) {
    // À implémenter :
    // 1. Tant que le caractère actuel n'est pas '\0'
    while(*chaine != '\0'){
        chaine++;
    
    // 2. Si le caractère actuel correspond à celui recherché
        if(*chaine == caractere){
    // 3. Retourner le pointeur vers cette position
            return (char*) chaine;
        }
        else{
    // 4. Si non trouvé, retourner NULL
             return nullptr;
        }
    }
    return 0;
}

    

size_t CompterOccurrences(const char* chaine, char caractere) {
    // À implémenter :
    // 1. Initialiser un compteur à 0
    size_t compteur = 0;
    // 2. Pour chaque caractère jusqu'au '\0'
        while (*chaine != 0){
    // 3. Si caractère correspond, incrémenter compteur
            if(*chaine == caractere){
                compteur++;
                chaine++;
            }
        }
    // 4. Retourner le compteur final
    return compteur;  
}

void CopierMemoire(void* destination, const void* source, size_t taille) {
    // À implémenter :
    // 1. Convertir les pointeurs en unsigned char*
    
    unsigned char* d = (unsigned char*) destination;
    const unsigned char* s = (const unsigned char*) source;
    // 2. Pour chaque octet de 0 à taille-1
        for (i=0; i < taille; i++){
    // 3. Copier l'octet source vers destination
            d[i] = s[i];
        }
    
    // 4. Avancer les deux pointeurs
    d++;
    s++;
}
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {

    // À implémenter :
    // 1. Convertir zone en unsigned char*
    unsigned char* z = (unsigned char*) zone;
    // 2. Pour chaque octet de 0 à taille-1
    for(i=0; i < taille; i++){
    // 3. Écrire la valeur dans l'octet
        z[i]=valeur;
    }
     // 4. Avancer le pointeur
    z++;

}
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur) {
    // À implémenter :
    // 1. Vérifier que debut est dans les limites de source
    size_t longu = LongueurChaine(source);
    if (longu > longueur) {
        std::cout << "fausse longueur\n";
    }
    // 2. Pour chaque caractère de 0 à longueur-1
    for (i=0; i < longueur; i++) {
    // 3. Copier source[debut+i] vers destination[i]
    destination[i] = source[debut + i];
    // 4. S'arrêter si on rencontre '\0' dans source
        if (source[debut + i] == '\0') {
            break;
         }
    }
    // 5. Ajouter '\0' à la fin de destination
            *destination = '\0';
}

size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats) {
    char caractere;
    // À implémenter :
    // 1. Initialiser compteur_resultats = 0, index_courant = 0
    size_t compteur_resultats = 0;
    size_t index_courant = 0;
    // 2. Pour chaque caractère de chaine jusqu'au '\0'
    while(*chaine != '\0'){
        // 3. Si caractère = séparateur OU fin de chaîne
           if(*chaine == separateur ||*chaine == '\0'){
            // 4.   Copier la sous-chaîne dans resultat[compteur_resultats]
                resultat[compteur_resultats] = *chaine;
            // 5.   Incrémenter compteur_resultats   
            compteur_resultats++;
            // 6.   Réinitialiser index_courant
            index_courant = 0;
            }
        // 7. Sinon ajouter le caractère à la sous-chaîne courante
            else{
                *chaine = caractere;
            }
        chaine++;
     }
     // 8. Retourner compteur_resultats
     return compteur_resultats;
}
 int ComparerChaines(const char* chaine1, const char* chaine2) {
    // À implémenter :
    // 1. Tant que chaine1 et chaine1 ne sont pas '\0'
    while(*chaine1 != '\0' && *chaine2 != '\0'){
        // 2. Si les caractères courants sont différents
        if(*chaine1 != *chaine2){
            // 3. Retourner la différence (chaine1 - chaine2)
            return chaine1 - chaine2;
        }
    }
    // 4. Si fin des deux chaînes, retourner 0
    if(*chaine1 == '\0' && *chaine2 == '\0'){
        return 0;
    }
    else{
         // 5. Sinon retourner la différence de longueur
         return chaine1 - chaine2;

    }  
    return 0;
}   
void ConvertirMinuscules(char* chaine) {
    // À implémenter :
    // 1. Pour chaque caractère jusqu'au '\0'
    while(*chaine != '\0'){
        // 2. Si le caractère est entre 'A' et 'Z'
        if(*chaine > 'A' && *chaine < 'Z'){
            // 3. Ajouter 32 pour le convertir en minuscule
            *chaine = *chaine + 32;
        }
        // 4. Sinon le laisser inchangé
        else{
            break;
        }
    }
}
bool EstChaineNumerique(const char* chaine) {
    // À implémenter :
    // 1. Si premier caractère est '-', avancer d'une position
    if(*chaine == '-'){
        chaine++;
    }
    // 2. Pour chaque caractère jusqu'au '\0'
    while(*chaine != 0){
        // 3. Si caractère n'est pas entre '0' et '9', retourner 0
        if(*chaine<0 || *chaine>9){
            return 0;
        }
        // 4. Si tous les caractères sont valides, retourner 1
        else{
            return 1;
        }
    }
    
     return false;
}

int main() {
  
    
    
    
     std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}
