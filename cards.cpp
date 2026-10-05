class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        //Primero se organizan las cartas de menor a mayor
        std::sort(deck.begin(), deck.end()); 
        //crear un nuevo vector, vacío, con el tamaño de deck
        std::vector<int> mazo_final(deck.size());
        //crear un nuevo vector, donde se van a ir guardando las posiciones que aún estén disponibles
        std::vector<int> posiciones_libres;
        //se llena el vector de las posiciones mediante un ciclo for que va a llenar de 0 al tamaño de deck   
        for (int i = 0; i < deck.size(); i++) {
            posiciones_libres.push_back(i);
        }
        //con otro ciclo for vamos llenando el mazo final
        for (int i = 0; i < deck.size();i++) {
                //obtenemos la posicion libre que está al frente del arreglo
                int pos_actual = posiciones_libres.front();
                //colocamos la carta que esté en la posición i del ciclo en la posición libre del arreglo en mazo_final
                mazo_final[pos_actual] = deck[i];
                //borramos la posición libre que está al frente del arreglo porque ya fue usada
                posiciones_libres.erase(posiciones_libres.begin()); 
                //nos preguntamos si todavía hay posiciones libres
                if (posiciones_libres.empty()==false) {
                    //si hay posiciones libres, obtenemos la sig posición libre del frente del arreglo
                    int pos_siguiente = posiciones_libres.front();
                    //borramos esa posición libre del inicio del arreglo
                    posiciones_libres.erase(posiciones_libres.begin());
                    //ponemos esa siguiente posición libre hasta el final del arreglo
                    posiciones_libres.push_back(pos_siguiente);
                }
        }
        //al terminar el ciclo, devolvemos el mazo que se armó
        return mazo_final;
    }
};
