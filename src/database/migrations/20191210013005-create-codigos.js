'use strict';

module.exports = {
  up: (queryInterface, Sequelize) => {
    
    return queryInterface.createTable('codigos', { 
      id:{
        type:Sequelize.INTEGER,
        primaryKey:true,
        autoIncrement:true,
        allowNull: false
      },
      mac:{
        type:Sequelize.STRING,
        allowNull: true
      },
      rssi:{
        type:Sequelize.STRING,
        allowNull: true
      },
      created_at:{
        type:Sequelize.DATE,
        allowNull: true
      },
      updated_at:{
        type:Sequelize.DATE,
        allowNull: true
      },
    });
    
  },

  down: (queryInterface, Sequelize) => {
    return queryInterface.dropTable('codigos');
    
  }
};