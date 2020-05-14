/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

typedef void (*fct_parcours_t)(xmlNodePtr);

void parcours_prefixe(xmlNodePtr noeud, fct_parcours_t f) {
    xmlNodePtr n;

    for (n = noeud; NULL != n; n = n->next) {
        f(n);
        if ((XML_ELEMENT_NODE == n->type) && (NULL != n->children)) {
            parcours_prefixe(n->children, f);
        }
    }
}

void parcours_postfixe(xmlNodePtr noeud, fct_parcours_t f) {
    xmlNodePtr n;

    for (n = noeud; n != NULL; n = n->next) {
        if ((XML_ELEMENT_NODE == n->type) && (NULL != n->children)) {
            parcours_postfixe(n->children, f);
        }
        f(n);
    }
}

void afficher_noeud(xmlNodePtr noeud) {
    if (XML_ELEMENT_NODE == noeud->type) {
        xmlChar *chemin = xmlGetNodePath(noeud);
        if (NULL != noeud->children && XML_TEXT_NODE == noeud->children->type) {
            xmlChar *contenu = xmlNodeGetContent(noeud);
            printf("%s -> %s\n", chemin, contenu);
            xmlFree(contenu);
        } else {
            printf("%s\n", chemin);
        }
        xmlFree(chemin);
    }
}

xmlNodePtr creer_user()
{
    xmlNodePtr user;

    user = xmlNewNode(NULL, BAD_CAST "user");

    xmlNewTextChild(user, NULL, BAD_CAST "uuid", BAD_CAST "test");
    xmlNewTextChild(user, NULL, BAD_CAST "username", BAD_CAST "username");
    xmlNewTextChild(user, NULL, BAD_CAST "password", BAD_CAST "password");
    xmlNewTextChild(user, NULL, BAD_CAST "date", BAD_CAST "14-05-2020 18:33:50");
    xmlNewTextChild(user, NULL, BAD_CAST "connected", BAD_CAST "false");

    return user;
}

int main() {
    xmlDocPtr doc;
    xmlNodePtr racine;

    // Ouverture du document
    xmlKeepBlanksDefault(0); // Ignore les noeuds texte composant la mise en forme
    if (NULL == (doc = xmlParseFile("test.xml"))) {
        fprintf(stderr, "Document XML invalide\n");
        return EXIT_FAILURE;
    }
    // Récupération de la racine
    if (NULL == (racine = xmlDocGetRootElement(doc))) {
        fprintf(stderr, "Document XML vierge\n");
        xmlFreeDoc(doc);
        return EXIT_FAILURE;
    }
    // Parcours
    xmlNodePtr newUser = creer_user();

    xmlAddChild(racine->children, newUser);


    printf("Parcours préfixé :\n");
    parcours_prefixe(racine, afficher_noeud);
    // Libération de la mémoire
    xmlSaveFile("output.xml", doc);
    xmlFreeDoc(doc);

    return EXIT_SUCCESS;
}