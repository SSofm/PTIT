import { IsString, IsNotEmpty, IsObject, IsOptional } from 'class-validator';
import { Cart } from '../../carts/entities/cart.entity';

export class CreateUserDto {
  @IsString()
  @IsNotEmpty()
  username: string;

  @IsNotEmpty()
  age: number;
  @IsString()
  @IsNotEmpty()
  password: string;
  @IsString()
  @IsNotEmpty()
  email: string;

  @IsObject()
  @IsOptional()
  cart: Cart;
}
