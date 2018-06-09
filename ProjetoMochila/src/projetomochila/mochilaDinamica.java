/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projetomochila;

import java.util.List;

/**
 *
 * @author erik_
 */
public class mochilaDinamica {
    /**Esta abordagem toma a mochila como vazia, com valor zero
     * e começamos a encher a mochila
     */

    public static int calcula(int capacidade, int[] pesos, int[] valores) {
        int n = pesos.length;
        int[][] matriz = new int[n + 1][capacidade + 1];
        for (int i = 0; i <= n; i++) {
            for (int v = 0; v <= capacidade; v++) {
                if ((i == 0) || (v == 0)) { // condição inicial
                    matriz[i][v] = 0; // mochila vazia
                } else
                    // se ainda ouver espaço na mochila 
                    if (pesos[i - 1 ] <= v) {
                        //compara com os pessos anteriormente inseridos
                    matriz[i][v] = Math.max(valores[i - 1] + matriz[i - 1][v - pesos[i - 1]], matriz[i - 1][v]);
                    //se o valor do novo item for maior e couber na mochila ele permanece
                } else {
                        //mochila ja esta cheia, não cabe novo item.
                    matriz[i][v] = matriz[i - 1][v];
                }
            }
        }
        //imprime a matriz calculada
        for (int i = 0; i <= n; i++) {
            for (int v = 0; v <= capacidade; v++){
                System.out.printf("%3d ", matriz[i][v]);
            }
            System.out.printf("\n");
        }
        return matriz[n][capacidade];
    }

    public static void main(String[] args) {
        int[] valores = {60, 100, 120};
        int[] pesos =   {10, 20, 30};
        int capacidade = 50;
        System.out.printf("Valor Maximo que coube na Mochila: %d\n", calcula(capacidade, pesos, valores));
    }

}
