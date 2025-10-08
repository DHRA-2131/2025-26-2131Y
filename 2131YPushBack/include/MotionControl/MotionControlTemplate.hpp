/**
 * @file MotionControlTemplate.hpp
 * @author Quinn Bracken
 * @brief Template for Motion Control Variants - Singleton
 * @version V1.0
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 class MotionControlTemplate
 {
    private:
        /* Private Vars Go Here */

        /* Make Inaccessable outside of class*/
        MotionControlTemplate() = default;
    
    public:

        MotionControlTemplate(const MotionControlTemplate&) = delete; //Delete Copy Constructor
        MotionControlTemplate& operator=(MotionControlTemplate const&) = delete; //Had trouble understanding this, but types are read from right to left (For future reference)

        void initialize(/* Nessisary Variables go Here*/); //Will need to pass a reference of chassis too but that is not created at this time
        MotionControlTemplate* Instance(); //Returns single instance of object

        /* Functions for motion controller go here */

 };