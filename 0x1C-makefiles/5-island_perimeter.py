#!/usr/bin/python3

"""
This Module contains the solution to the island perimeter problem
"""


def num_water_neighbors(grid, i, j):
    """
    Returns the number of water neighbors of a cell in a grid

    Returns:
        int: the number of water neighbors
    """

    number = 0

    if i <= 0 or not grid[i - 1][j]:
        number += 1
    if j <= 0 or not grid[i][j - 1]:
        number += 1
    if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
        number += 1
    if i >= len(grid) - 1 or not grid[i + 1][j]:
        number += 1

    return number


def island_perimeter(grid):
    """Returns the perimeter of an island in a grid"""

    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                perimeter += num_water_neighbors(grid, i, j)

    return perimeter
