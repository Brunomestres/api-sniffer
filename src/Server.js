const express = require('express');
const bodyParser = require('body-parser');
const routes = require('./Routes');
require('./database')

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended:true}));
app.use(routes);



app.listen(3333,()=>{
    console.log('Servidor ON');
});