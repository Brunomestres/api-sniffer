const { Model, DataTypes } = require('sequelize');


class Codigo extends Model{
    static init(sequelize)
    {
        super.init({
            mac:DataTypes.STRING,
            rssi:DataTypes.STRING
        },{
            sequelize
        })
    }
}

module.exports = Codigo;