import tkinter as tk
from tkinter import ttk

class UnitConverter:
    def __init__(self, root):
        self.root = root
        self.root.title("单位换算器")
        
        # 创建主框架
        self.main_frame = ttk.Frame(root, padding="10")
        self.main_frame.grid(column=0, row=0, sticky=(tk.W, tk.E, tk.N, tk.S))
        
        # 单位类型选择
        self.unit_type = tk.StringVar()
        self.unit_type.set("长度")
        ttk.Label(self.main_frame, text="选择单位类型:").grid(column=0, row=0)
        self.unit_menu = ttk.OptionMenu(self.main_frame, self.unit_type, "长度", "长度", "重量", "温度", "货币")
        self.unit_menu.grid(column=1, row=0)
        
        # 输入框
        ttk.Label(self.main_frame, text="输入值:").grid(column=0, row=1)
        self.input_value = tk.DoubleVar()
        self.input_entry = ttk.Entry(self.main_frame, textvariable=self.input_value)
        self.input_entry.grid(column=1, row=1)
        
        # 转换按钮
        self.convert_btn = ttk.Button(self.main_frame, text="转换", command=self.convert)
        self.convert_btn.grid(column=2, row=1)
        
        # 结果显示
        self.result_label = ttk.Label(self.main_frame, text="结果:")
        self.result_label.grid(column=0, row=2, columnspan=3)
        
    def convert(self):
        """执行单位转换"""
        value = self.input_value.get()
        unit_type = self.unit_type.get()
        result = ""
        
        if unit_type == "长度":
            # 米、英尺、公里、英里转换
            meters = value
            feet = meters * 3.28084
            kilometers = meters / 1000
            miles = meters * 0.000621371
            result = f"{meters} 米 = {feet:.2f} 英尺\n{meters} 米 = {kilometers:.4f} 公里\n{meters} 米 = {miles:.4f} 英里"
            
        elif unit_type == "重量":
            # 克、千克、磅、盎司转换
            grams = value
            kilograms = grams / 1000
            pounds = grams * 0.00220462
            ounces = grams * 0.035274
            result = f"{grams} 克 = {kilograms:.4f} 千克\n{grams} 克 = {pounds:.4f} 磅\n{grams} 克 = {ounces:.4f} 盎司"
            
        elif unit_type == "温度":
            # 摄氏度、华氏度、开尔文转换
            celsius = value
            fahrenheit = (celsius * 9/5) + 32
            kelvin = celsius + 273.15
            result = f"{celsius}℃ = {fahrenheit:.2f}℉\n{celsius}℃ = {kelvin:.2f}K"
            
        elif unit_type == "货币":
            # 这里需要调用API获取实时汇率
            result = "货币转换功能需要调用API实现，暂未完成"
            
        self.result_label.config(text=f"结果:\n{result}")

if __name__ == "__main__":
    root = tk.Tk()
    app = UnitConverter(root)
    root.mainloop()