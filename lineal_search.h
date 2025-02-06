
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
 
#ifndef LINEAL_SEARCH_H
#define LINEAL_SEARCH_H

#include <vector>
#include <utility>
#include <cmath>
#include <limits>
using namespace std;

/**
 * @class LinealSearch
 * @brief Clase para realizar una búsqueda lineal de la central más cercana.
 *
 * Esta clase proporciona un método estático para encontrar la central más
 * cercana a un nuevo contrato, calculando la distancia euclidiana entre
 * los puntos proporcionados.
 * 
 * Complejidad O(n): Se recorre la lista de centrales para encontrar la más cercana
 */
class LinealSearch{
    public:

    /**
     * @brief Encuentra la central más cercana a un nuevo contrato.
     *
     * @param centrals Un vector de pares de enteros que representan las coordenadas
     *        de las centrales existentes.
     * @param new_contract Un par de enteros que representa la ubicación del nuevo contrato.
     * @return Un par de enteros que representa la central más cercana.
     */
    static pair<int, int> Find(const vector<pair<int, int>>& centrals, const pair<int, int>& new_contract){
        double min_distance = numeric_limits<double>::max();
        pair<int, int> closest_central;

        for (const auto& central: centrals){
            double distance = hypot(central.first - new_contract.first, central.second - new_contract.second);
            if (distance < min_distance){
                min_distance = distance;
                closest_central = central;
            }
        }
        return closest_central;
    }
};
# endif
