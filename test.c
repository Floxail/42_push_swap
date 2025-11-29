/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvejux <flvejux@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:23:47 by flvejux           #+#    #+#             */
/*   Updated: 2025/11/27 11:28:54 by flvejux          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
    int numbers[] = {3, 1, 4, 2, 5};  // Changé: pas de doublon pour mieux tester
    int count = 5;
    
    printf("=== Test 1: Créer une stack ===\n");
    t_stack *stack = create_stack(numbers, count);
    
    if (!stack)
    {
        printf("❌ Erreur création\n");
        return (1);
    }
    
    printf("✅ Stack créée\n");
    
    // Afficher manuellement
    t_stack *current = stack;
    printf("Contenu: ");
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
    
    printf("\n=== Test 2: Vérifier les liens ===\n");
    current = stack;
    int i = 0;
    while (current)
    {
        printf("Noeud %d: value=%d, next=%p, prev=%p\n", 
               i, current->value, (void *)current->next, (void *)current->prev);
        current = current->next;
        i++;
    }
    
    printf("\n=== Test 3: Parcourir en arrière ===\n");
    // Aller au dernier
    current = stack;
    while (current->next)
        current = current->next;
    
    // Revenir en arrière
    printf("Arrière: ");
    while (current)
    {
        printf("%d ", current->value);
        current = current->prev;
    }
    printf("\n");
    
    printf("\n=== Test 4: Swap ===\n");
    printf("Avant swap: ");
    current = stack;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
    
    swap(&stack);  // ← Passe l'adresse !
    
    printf("Après swap: ");
    current = stack;  // ← Réinitialiser !
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
    
    printf("Liens après swap:\n");
    current = stack;
    i = 0;
    while (current)
    {
        printf("Noeud %d: value=%d, next=%p, prev=%p\n", 
               i, current->value, (void *)current->next, (void *)current->prev);
        current = current->next;
        i++;
    }
    
    printf("\n=== Test 5: Free ===\n");
    free_stack(stack);
    printf("✅ Tout libéré\n");
    
    return (0);
}