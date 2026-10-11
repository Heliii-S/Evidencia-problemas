class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // Primero hay que contar cuántos nodos hay en total
        int tam = 0;
        // Crear un nodo nuevo para contar cuántos nodos hay
        ListNode* actual = head;
        // usamos un ciclo while para contar
        while (actual != NULL) {
            tam++;
            // vamos sumando uno al contador (tam) mientras haya una posición siguiente
            actual = actual->next;
        }
        // Inicializamos la variable suma donde va a guardarse el resultado
        int suma = 0;
        // Como ya sabemos el tamaño podemos conocer cual es la potencia más grande a la que se va a elevar dos
        int exponente = tam - 1; 
        // Recorremos el arreglo nuevamente para ir sumando cada valor por 2^exponente y sumar
        while (head != NULL) {
            //Vamos multiplicando el valor por 2^exponente y sumando
            suma += head->val * pow(2, exponente);
            // Reducimos la potencia para el siguiente nodo
            exponente--; 
            head = head->next;
        }
        // Al final, devolvemos la suma que obtuvimos
        return suma;
    }
};
