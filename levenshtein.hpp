#pragma once
#include <string_view>
#include <vector>
#include <array>
#include <algorithm>

namespace levenshtein
{
    unsigned int calculate_distance(std::string_view a, std::string_view b)
    {
        const auto m = a.size();
        const auto n = b.size();

        // initialize matrix
        std::vector<std::vector<unsigned int>> matrix;
        matrix.resize(m+1);
        for (std::size_t i=0; i<=m; ++i) 
        {
            matrix[i].reserve(n+1);
        }

        //Initialize border values
        for (unsigned int i=0; i<=m; ++i) 
        {
            matrix[i][0] = i;
        }
        for (unsigned int i=0; i<=n; ++i) 
        {
            matrix[0][i] = i;
        }

        // Now let's get to business
        for (unsigned int i=0; i<m; i++) 
        {
            for (unsigned int j=0; j<n; j++) 
            {
                if(a.at(i) == b.at(j))
                {
                    matrix[i+1][j+1] = matrix[i][j];
                    continue;
                }

                std::array<unsigned int,3> potentials{};
                potentials[0] = matrix[i][j] + 1;
                potentials[1] = matrix[i+1][j] + 1;
                potentials[2] = matrix[i][j+1] + 1;
                matrix[i+1][j+1] = std::ranges::min(potentials);
            }
        }

        return matrix[m][n];
    }

}
