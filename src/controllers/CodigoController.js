const Codigo = require('../models/Codigo');

module.exports = {
    async index(req,res)
    {
        const codigo = await Codigo.findAll();
        return res.json(codigo);
    },

    async store(req,res)
    {
        const { probes } = req.body;

        const address = probes.map((probe)=>{
            return probe.address;
        });
        const newAddress = address[1];
        const newRssi = probes.map((probe)=>{
            return probe.rssi;
        });
        const codigo = await Codigo.create({
            mac:newAddress,
            rssi:newRssi[1]
        });
        console.log(codigo);
    }
}