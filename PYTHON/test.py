from pprint import pprint
# effect is the given dictionary in question!
effect = {
    "super effective": {
        "Normal": [],
        "Fire": [
            "Grass",
            "Ice",
            "Bug",
            "Steel"
        ],
        "Water": [
            "Fire",
            "Ground",
            "Rock"
        ],
        "Electric": [
            "Water",
            "Flying"
        ],
        "Grass": [
            "Water",
            "Ground",
            "Rock"
        ],
        "Ice": [
            "Grass",
            "Ground",
            "Flying",
            "Dragon"
        ],
        "Fighting": [
            "Normal",
            "Ice",
            "Rock",
            "Dark",
            "Steel"
        ],
        "Poison": [
            "Grass",
            "Fairy"
        ],
        "Ground": [
            "Fire",
            "Electric",
            "Poison",
            "Rock",
            "Steel"
        ],
        "Flying": [
            "Grass",
            "Fighting",
            "Bug"
        ],
        "Psychic": [
            "Fighting",
            "Poison"
        ],
        "Bug": [
            "Grass",
            "Psychic",
            "Dark"
        ],
        "Rock": [
            "Fire",
            "Ice",
            "Flying",
            "Bug"
        ],
        "Ghost": [
            "Psychic",
            "Ghost"
        ],
        "Dragon": [
            "Dragon"
        ],
        "Dark": [
            "Psychic",
            "Ghost"
        ],
        "Steel": [
            "Ice",
            "Rock",
            "Fairy"
        ],
        "Fairy": [
            "Fighting",
            "Dragon",
            "Dark"
        ]
    },
    "normal effective": {
        "Normal": [
            "Normal",
            "Fire",
            "Water",
            "Electric",
            "Grass",
            "Ice",
            "Fighting",
            "Poison",
            "Ground",
            "Flying",
            "Psychic",
            "Bug",
            "Dragon",
            "Dark",
            "Fairy"
        ],
        "Fire": [
            "Normal",
            "Electric",
            "Fighting",
            "Poison",
            "Ground",
            "Flying",
            "Psychic",
            "Ghost",
            "Dark",
            "Fairy"
        ],
        "Water": [
            "Normal",
            "Electric",
            "Ice",
            "Fighting",
            "Poison",
            "Flying",
            "Psychic",
            "Bug",
            "Ghost",
            "Dark",
            "Steel",
            "Fairy"
        ],
        "Electric": [
            "Normal",
            "Fire",
            "Ice",
            "Fighting",
            "Poison",
            "Psychic",
            "Bug",
            "Rock",
            "Ghost",
            "Dark",
            "Steel",
            "Fairy"
        ],
        "Grass": [
            "Normal",
            "Electric",
            "Ice",
            "Fighting",
            "Psychic",
            "Ghost",
            "Dark",
            "Fairy"
        ],
        "Ice": [
            "Normal",
            "Electric",
            "Fighting",
            "Poison",
            "Psychic",
            "Bug",
            "Rock",
            "Ghost",
            "Dark",
            "Fairy"
        ],
        "Fighting": [
            "Fire",
            "Water",
            "Electric",
            "Grass",
            "Fighting",
            "Ground",
            "Dragon"
        ],
        "Poison": [
            "Normal",
            "Fire",
            "Water",
            "Electric",
            "Ice",
            "Fighting",
            "Flying",
            "Psychic",
            "Bug",
            "Dragon",
            "Dark"
        ],
        "Ground": [
            "Normal",
            "Water",
            "Ice",
            "Fighting",
            "Ground",
            "Psychic",
            "Ghost",
            "Dragon",
            "Dark",
            "Fairy"
        ],
        "Flying": [
            "Normal",
            "Fire",
            "Water",
            "Ice",
            "Poison",
            "Ground",
            "Flying",
            "Psychic",
            "Ghost",
            "Dragon",
            "Dark",
            "Fairy"
        ],
        "Psychic": [
            "Normal",
            "Fire",
            "Water",
            "Electric",
            "Grass",
            "Ice",
            "Ground",
            "Flying",
            "Bug",
            "Rock",
            "Ghost",
            "Dragon",
            "Fairy"
        ],
        "Bug": [
            "Normal",
            "Water",
            "Electric",
            "Ice",
            "Ground",
            "Bug",
            "Rock",
            "Dragon"
        ],
        "Rock": [
            "Normal",
            "Water",
            "Electric",
            "Grass",
            "Poison",
            "Psychic",
            "Rock",
            "Ghost",
            "Dragon",
            "Dark",
            "Fairy"
        ],
        "Ghost": [
            "Fire",
            "Water",
            "Electric",
            "Grass",
            "Ice",
            "Fighting",
            "Poison",
            "Ground",
            "Flying",
            "Bug",
            "Rock",
            "Dragon",
            "Steel",
            "Fairy"
        ],
        "Dragon": [
            "Normal",
            "Fire",
            "Water",
            "Electric",
            "Grass",
            "Ice",
            "Fighting",
            "Poison",
            "Ground",
            "Flying",
            "Psychic",
            "Bug",
            "Rock",
            "Ghost",
            "Dark"
        ],
        "Dark": [
            "Normal",
            "Fire",
            "Water",
            "Electric",
            "Grass",
            "Ice",
            "Poison",
            "Ground",
            "Flying",
            "Bug",
            "Rock",
            "Dragon",
            "Steel"
        ],
        "Steel": [
            "Normal",
            "Grass",
            "Fighting",
            "Poison",
            "Ground",
            "Flying",
            "Psychic",
            "Bug",
            "Ghost",
            "Dragon",
            "Dark"
        ],
        "Fairy": [
            "Normal",
            "Water",
            "Electric",
            "Grass",
            "Ice",
            "Ground",
            "Flying",
            "Psychic",
            "Bug",
            "Rock",
            "Ghost",
            "Fairy"
        ]
    },
    "not very effective": {
        "Normal": [
            "Rock",
            "Steel"
        ],
        "Fire": [
            "Fire",
            "Water",
            "Rock",
            "Dragon"
        ],
        "Water": [
            "Water",
            "Grass",
            "Dragon"
        ],
        "Electric": [
            "Electric",
            "Grass",
            "Dragon"
        ],
        "Grass": [
            "Fire",
            "Grass",
            "Poison",
            "Flying",
            "Bug",
            "Dragon",
            "Steel"
        ],
        "Ice": [
            "Fire",
            "Water",
            "Ice",
            "Steel"
        ],
        "Fighting": [
            "Poison",
            "Flying",
            "Psychic",
            "Bug",
            "Fairy"
        ],
        "Poison": [
            "Poison",
            "Ground",
            "Rock",
            "Ghost"
        ],
        "Ground": [
            "Grass",
            "Bug"
        ],
        "Flying": [
            "Electric",
            "Rock",
            "Steel"
        ],
        "Psychic": [
            "Psychic",
            "Steel"
        ],
        "Bug": [
            "Fire",
            "Fighting",
            "Poison",
            "Flying",
            "Ghost",
            "Steel",
            "Fairy"
        ],
        "Rock": [
            "Fighting",
            "Ground",
            "Steel"
        ],
        "Ghost": [
            "Dark"
        ],
        "Dragon": [
            "Steel"
        ],
        "Dark": [
            "Fighting",
            "Dark",
            "Fairy"
        ],
        "Steel": [
            "Fire",
            "Water",
            "Electric",
            "Steel"
        ],
        "Fairy": [
            "Fire",
            "Poison",
            "Steel"
        ]
    },
    "no effect": {
        "Normal": [
            "Ghost"
        ],
        "Fire": [],
        "Water": [],
        "Electric": [
            "Ground"
        ],
        "Grass": [],
        "Ice": [],
        "Fighting": [
            "Ghost"
        ],
        "Poison": [
            "Steel"
        ],
        "Ground": [
            "Flying"
        ],
        "Flying": [],
        "Psychic": [
            "Dark"
        ],
        "Bug": [],
        "Rock": [],
        "Ghost": [
            "Normal"
        ],
        "Dragon": [
            "Fairy"
        ],
        "Dark": [],
        "Steel": [],
        "Fairy": []
    }
}
dict = {}
types = []

for a in effect['no effect']:
        types.append(a)

types = list(set(types))

for a in types:
    dict[a] = {}
    for b in types:
        dict[a][b] = 0.0

for a in effect:
    for b in effect[a]:
        for c in effect[a][b]:
            if a == "super effective":
                dict[b][c] = 2.0
            if a == "normal effective":
                dict[b][c] = 1.0
            if a == "not very effective":
                dict[b][c] = 0.5

# pprint(dict)
# print(dict['Fire']['Fire'])
# print(dict['Fire']['Poison'])
# print(dict['Dark']['Ghost'])
# print(dict['Dark']['Ice'])

n1 = int(input())
n2 = int(input())
team1 = []
team2 = []
for i in range(n1):
    team1.append(str(input()))
for i in range(n2):
    team2.append(str(input()))

score1 = 0.0
score2 = 0.0

for pokemon1 in team1:
    for pokemon2 in team2:
        type1 = pokemon1.split(' ')
        type2 = pokemon2.split(' ')

        if len(type1) == 2 and len(type2) == 1:
            score1 += max(dict[type1[0]][type2[0]], dict[type1[1]][type2[0]])
            score2 += dict[type2[0]][type1[0]]*dict[type2[0]][type1[1]]

        elif len(type1) == 2 and len(type2) == 2:
            score1 += max(dict[type1[0]][type2[0]] * dict[type1[0]][type2[1]], dict[type1[1]][type2[0]]*dict[type1[1]][type2[1]])
            score2 += max(dict[type2[0]][type1[0]] * dict[type2[0]][type1[1]], dict[type2[1]][type1[0]]*dict[type2[1]][type1[1]])
        
        elif len(type1) == 1 and len(type2) == 1:
            score1 += dict[type1[0]][type2[0]]
            score2 += dict[type2[0]][type1[0]]
        
        elif len(type1) == 1 and len(type2) == 2:
            score1 += dict[type1[0]][type2[0]]*dict[type1[0]][type2[1]]
            score2 += max(dict[type2[0]][type1[0]], dict[type2[1]][type1[0]])

print(score1)
print(score2)
if score1 > score2:
    print("ME")
elif score1 < score2:
    print("FOE")
else:
    print("EQUAL")