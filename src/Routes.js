const express = require('express');
const CodigoController = require('./controllers/CodigoController');
const routes = express.Router();

routes.get('/sniffer',CodigoController.index);
routes.post('/sniffer',CodigoController.store);

module.exports = routes;