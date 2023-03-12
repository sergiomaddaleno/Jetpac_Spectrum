
//Para guardar la informacion pulsando 's'
void WriteGameData(){

    if (esat::IsKeyDown('S')){

        fSave=fopen("GameData.dat", "wb");
        fwrite(&levelCount, sizeof(int),1, fSave);
        fwrite(&levelShip, sizeof(int),1, fSave);
        fwrite(&score1, sizeof(int),1, fSave);
        fwrite(&life1, sizeof(int),1, fSave);
    
        fclose(fSave);
    }
}

void ReadGameData(){

    int value;
    if ((fSave=fopen("GameData.dat","rb")) != NULL){
        
        fread(&value,sizeof(value),1,fSave);
        levelCount = value;

        fread(&value,sizeof(value),1,fSave);
        levelShip = value;

        fread(&value,sizeof(value),1,fSave);
        score1 = value;

        fread(&value,sizeof(value),1,fSave);
        life1 = value;

        fclose(fSave);
        
    }
}


