#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

const url = `https://swapi-api.alx-tools.com/api/films/${movieId}`;

request(url, (err, response, body) => {
  if (err) return console.error(err);

  const characters = JSON.parse(body).characters;

  const fetchCharacters = (index) => {
    if (index >= characters.length) return;
    request(characters[index], (err2, _, body2) => {
      if (!err2) {
        const name = JSON.parse(body2).name;
        console.log(name);
        fetchCharacters(index + 1);
      }
    });
  };

  fetchCharacters(0);
});
