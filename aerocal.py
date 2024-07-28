from tkinter import Tk, Label, Entry, Button

# Function to calculate coefficients
def calculate_coefficients():
    try:
        # Get user inputs from entry fields
        drag_force = float(drag_force_entry.get())
        lift_force = float(lift_force_entry.get())
        ref_area = float(ref_area_entry.get())
        inlet_velocity = float(inlet_velocity_entry.get())
        density = float(density_entry.get())
        wing_span = float(wing_span_entry.get())
        chord_length = float(chord_length_entry.get())

        # Calculate drag and lift coefficients
        drag_coefficient = drag_force / (0.5 * density * inlet_velocity ** 2 * ref_area)
        lift_coefficient = lift_force / (0.5 * density * inlet_velocity ** 2 * ref_area)

        # Calculate aspect ratio
        aspect_ratio = (wing_span ** 2) / ref_area

        # Calculate induced drag coefficient
        induced_drag_coefficient = (lift_force ** 2 / (3.14159 * aspect_ratio))

        # Calculate moment coefficient
        moment_coefficient = 0.25 * chord_length * (lift_force / (0.5 * density * inlet_velocity ** 2 * ref_area)) 

        # Update text boxes with results
        drag_coeff_label.config(text=f"Drag Coefficient: {drag_coefficient:.4f}")
        lift_coeff_label.config(text=f"Lift Coefficient: {lift_coefficient:.4f}")
        aspect_ratio_label.config(text=f"Aspect Ratio: {aspect_ratio:.4f}")
        induced_drag_coefficient_label.config(text=f"Induced Drag Coefficient: {induced_drag_coefficient:.4f}")
        moment_coeff_label.config(text=f"Moment Coefficient: {moment_coefficient:.4f}")
    except ValueError:
        # Handle invalid user input
        drag_coeff_label.config(text="Error: Invalid Input!")
        lift_coeff_label.config(text="Error: Invalid Input!")
        aspect_ratio_label.config(text="Error: Invalid Input!")
        induced_drag_coefficient_label.config(text="Error: Invalid Input!")
        moment_coeff_label.config(text="Error: Invalid Input!")


# Create the main window
root = Tk()
root.title("Aerodynamic Calculator")

# Create labels and entry fields
drag_force_label = Label(root, text="Drag Force (N):")
drag_force_label.grid(row=0, column=0, padx=5, pady=5)

drag_force_entry = Entry(root)
drag_force_entry.grid(row=0, column=1, padx=5, pady=5)

lift_force_label = Label(root, text="Lift Force (N):")
lift_force_label.grid(row=1, column=0, padx=5, pady=5)

lift_force_entry = Entry(root)
lift_force_entry.grid(row=1, column=1, padx=5, pady=5)

ref_area_label = Label(root, text="Reference Area (m^2):")
ref_area_label.grid(row=2, column=0, padx=5, pady=5)

ref_area_entry = Entry(root)
ref_area_entry.grid(row=2, column=1, padx=5, pady=5)

inlet_velocity_label = Label(root, text="Inlet Velocity (m/s):")
inlet_velocity_label.grid(row=3, column=0, padx=5, pady=5)

inlet_velocity_entry = Entry(root)
inlet_velocity_entry.grid(row=3, column=1, padx=5, pady=5)

density_label = Label(root, text="Density (kg/m^3):")
density_label.grid(row=4, column=0, padx=5, pady=5)

density_entry = Entry(root)
density_entry.grid(row=4, column=1, padx=5, pady=5)

wing_span_label = Label(root, text="Wing Span (m):")
wing_span_label.grid(row=5, column=0, padx=5, pady=5)

wing_span_entry = Entry(root)
wing_span_entry.grid(row=5, column=1, padx=5, pady=5)

chord_length_label = Label(root, text="Chord Length (m):")
chord_length_label.grid(row=6, column=0, padx=5, pady=5)

chord_length_entry = Entry(root)
chord_length_entry.grid(row=6, column=1, padx=5, pady=5)

# Create button to trigger calculation
calculate_button = Button(root, text="Calculate", command=calculate_coefficients)
calculate_button.grid(row=7, columnspan=2, padx=5, pady=5)

# Create labels for displaying results
drag_coeff_label = Label(root, text="Drag Coefficient:")
drag_coeff_label.grid(row=8, column=0, padx=5, pady=5)

lift_coeff_label = Label(root, text="Lift Coefficient:")
lift_coeff_label.grid(row=9, column=0, padx=5, pady=5)

aspect_ratio_label = Label(root, text="Aspect Ratio:")
aspect_ratio_label.grid(row=10, column=0, padx=5, pady=5)

induced_drag_coefficient_label = Label(root, text="Induced Drag Coefficient:")
induced_drag_coefficient_label.grid(row=11, column=0, padx=5, pady=5)

moment_coeff_label = Label(root, text="Moment Coefficient:")
moment_coeff_label.grid(row=12, column=0, padx=5, pady=5)

# Run the main loop
root.mainloop()
