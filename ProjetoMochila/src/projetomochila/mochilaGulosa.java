/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projetomochila;

import java.util.ArrayList;

/**
 *
 * @author erik_
 */
public class mochilaGulosa {

    /**
     * Esta abordagem toma a mochila como vazia, com valor zero e começamos a
     * encher a mochila pelo item de melhor custo beneficio
     */
    public static int calculaCusto(int capacidade, int[] pesos, int[] valores) {
        int n = pesos.length, aux1, aux2, ocupado = 0, valorFinal = 0;
        float x, aux;
        ArrayList<Float> custo = new ArrayList();
        for (int i = 0; i < n; i++) {
            x = (float) valores[i] / pesos[i];
            custo.add(x);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (custo.get(i) > custo.get(j)) {
                    aux1 = valores[i];
                    aux2 = pesos[i];
                    aux = custo.get(i);
                    valores[i] = valores[j];
                    pesos[i] = pesos[j];
                    custo.set(i, custo.get(j));
                    valores[j] = aux1;
                    pesos[j] = aux2;
                    custo.set(j, aux);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if ((ocupado + pesos[i]) <= capacidade) {
                ocupado += pesos[i];
                valorFinal += valores[i];
            }
        }

        for (int i = 0; i < n; i++) {
            //imprime o custo de cada item;
            System.out.printf("ordenado pelo custo %d de Valor %d e: %f \n", pesos[i], valores[i], custo.get(i));
        }
        return valorFinal;
    }

    public static void main(String[] args) {
        int[] valores = {60, 100, 120};
        int[] pesos = {10, 20, 30};
        int capacidade = 50;
        System.out.printf("Valor Maximo que coube na Mochila: %d\n", calculaCusto(capacidade, pesos, valores));
    }

}
