const Sequelize = require('sequelize');
const dbConfig = require('../config/DB');

const Codigo = require('../models/Codigo');

const connection = new Sequelize(dbConfig);

Codigo.init(connection);

module.exports = connection;