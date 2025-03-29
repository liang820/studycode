document.addEventListener('DOMContentLoaded', function() {
    const unitTypeSelect = document.getElementById('unit-type');
    const inputValue = document.getElementById('input-value');
    const convertBtn = document.getElementById('convert-btn');
    const resultContent = document.getElementById('result-content');

    convertBtn.addEventListener('click', convertUnits);

    function convertUnits() {
        const value = parseFloat(inputValue.value);
        const unitType = unitTypeSelect.value;
        let result = "";

        if (isNaN(value)) {
            resultContent.textContent = "请输入有效的数值";
            return;
        }

        switch(unitType) {
            case 'length':
                // 米、英尺、公里、英里转换
                const feet = value * 3.28084;
                const kilometers = value / 1000;
                const miles = value * 0.000621371;
                result = `${value} 米 = ${feet.toFixed(2)} 英尺\n${value} 米 = ${kilometers.toFixed(4)} 公里\n${value} 米 = ${miles.toFixed(4)} 英里`;
                break;
            
            case 'weight':
                // 克、千克、磅、盎司转换
                const kilograms = value / 1000;
                const pounds = value * 0.00220462;
                const ounces = value * 0.035274;
                result = `${value} 克 = ${kilograms.toFixed(4)} 千克\n${value} 克 = ${pounds.toFixed(4)} 磅\n${value} 克 = ${ounces.toFixed(4)} 盎司`;
                break;
            
            case 'temperature':
                // 摄氏度、华氏度、开尔文转换
                const fahrenheit = (value * 9/5) + 32;
                const kelvin = value + 273.15;
                result = `${value}℃ = ${fahrenheit.toFixed(2)}℉\n${value}℃ = ${kelvin.toFixed(2)}K`;
                break;
            
            case 'currency':
                result = "货币转换功能需要调用API实现，暂未完成";
                break;
        }

        resultContent.textContent = result;
    }
});